#include "sqlfunctions.h"

sqlfunctions::sqlfunctions(){
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("kinectsrv.lfb.rwth-aachen.de");
    db.setDatabaseName("kinectshop2015");
    db.setUserName("kinectshopClient");
    db.setPassword("lfb-student2015");
    db.setPort(3306);
    qDebug()<<db.open();

    isLogin = 0;
}

// ----------------------------------------------------------------------------------
// --------------------------------------WAREZMGMT-----------------------------------
// ----------------------------------------------------------------------------------

// Füge Element in den Warenkorb ein
void sqlfunctions::addToCart(product myProduct){
    product newProduct = isAlreadyInCart(myProduct);
    cart.push_back(newProduct);
}

// Überprüft, ob ein Element bereits im Warenkorb ist, falls ja erhöhe nur die Menge
// Gibt hinzuzufügendes Produkt an addToCart() zurück.
product sqlfunctions::isAlreadyInCart(product myProduct){
    iter cursor = find(cart.begin(), cart.end(), myProduct.getPid());
    if(cursor!=cart.end()){

        int newAmount = myProduct.getAmount() + cursor->getAmount();
        myProduct.setAmount(newAmount);
        cart.erase(cursor);
    }
    return myProduct;
}

// Löscht Produkt aus Einkaufswagen
void sqlfunctions::removeFromCart(product myProduct){
    iter cursor = find(cart.begin(), cart.end(), myProduct.getPid());
    cart.erase(cursor);
}

// Gibt den Inhalt des Einkaufswagens aus, bereits HTML
// Überdenken!
void sqlfunctions::showCart(){

    cout    <<  "<table id='cart'>"   << endl;
    for(iter cursor = cart.begin();cursor!=cart.end();cursor++){
        cout    <<  "<tr> "     << endl;
        cout    <<  "<td>"      <<  "Produkt-ID: "      << cursor->getPid()       << "</td>"      << endl;
        cout    <<  "<td>"      <<  "Produktname: "     << cursor->getTitle()     << "</td>"      << endl;
        cout    <<  "<td>"      <<  "Menge: "           << cursor->getAmount()    << "</td>"      << endl;
        cout    <<  "</tr> "    <<  endl;
    }
    cout    <<  "</table>"   << endl;

}

// Leert den Einkaufswagen
void sqlfunctions::clearCart(){
    int size = cart.size();
    while(size){
        cart.pop_back();
        --size;
    }
}

// Wenn man unzufrieden ist mit der Menge an eingekauften Waren, kann man diese ändern.
void sqlfunctions::changeAmount(product myProduct, int newAmount){
    myProduct.setAmount(newAmount);
}

// Prüft für jede Ware im Warenkorb, ob noch genug Waren vorhanden sind
int sqlfunctions::checkStock(){
    QSqlQuery query;
    int diff, stock;
    for(iter cursor = cart.begin();cursor!=cart.end();cursor++){
        query.prepare("SELECT stock FROM products WHERE id = :input");
        query.bindValue(":input", cursor->getPid());
        query.exec();
        // Need to save result of query into variable stock       
        query.next();
        stock = query.value(0).toInt();
        diff = stock - cursor->getAmount();
    }
    return diff;
}

// Prüft, ob der Benutzer ausreichend Guthaben zum Kauf hat.
// UNVOLLSTÄNDIG!!
int sqlfunctions::checkBalance(){
    // ermittelt Gesamtkosten des Warenkorbs
    int total = 0;
    for(iter cursor = cart.begin(); cursor!=cart.end(); cursor++){
        total += (cursor->getPrice() * cursor->getAmount());
    }
    // Vergleiche Guthaben mit Gesamtkosten
    int balance;
    return balance - total;
}

// Die Bezahlfunktion
void sqlfunctions::purchase(){
    QSqlQuery query;
    // Überprüfe, ob User eingeloogt ist.
    if(isLogin){
        int hasEnoughMoney = checkBalance();
        // Überprüfe ob User genug Guthaben hat.
        if(hasEnoughMoney >= 0){
            int diff = checkStock();
            if(diff >= 0){
                for(iter cursor = cart.begin(); cursor != cart.end(); ++cursor){

                    int pid = cursor->getPid();
                    int amount = cursor->getAmount();

                    // SQL-Befehle für den Bezahlvorgang
                    // Buchungstabelle
                    // größte Buchungsnummer ermitteln
                    query.prepare("SELECT MAX(id) FROM bookings");
                    query.exec();
                    query.next();
                    int insertId = query.value(0).toInt();
                    // Buchungsnummer um 1 erhöhen
                    insertId++;
                    query.prepare("INSERT INTO bookings (id,uid,pid,amount) VALUES (:id, :uid, :pid, :amount)");
                    query.bindValue(":id", insertId);
                    query.bindValue(":uid", uid);
                    query.bindValue(":pid", pid);
                    query.bindValue(":amount", amount);
                    query.exec();

                    // Kosten ausrechnen
                    query.prepare("SELECT price FROM products WHERE id =:pid");
                    query.bindValue(":pid", pid);
                    query.exec();

                    query.next();
                    double price = query.value(0).toDouble();
                    double cost = (double)amount*price;

                    query.prepare("SELECT balance FROM users WHERE id = :uid");
                    query.bindValue(":uid", uid);
                    query.exec();
                    query.next();
                    double balance = query.value(0).toDouble();
                    double newBalance = balance - cost;

                    // Userguthaben abbuchen
                    query.prepare("UPDATE users SET balance=:newBalance WHERE id =:uid");
                    query.bindValue(":newBalance", newBalance);
                    query.bindValue(":uid", uid);
                    query.exec();

                    // Produktvorrat reduzieren
                    query.prepare("SELECT stock FROM products WHERE id = :pid");
                    query.bindValue(":pid", pid);
                    query.exec();
                    query.next();
                    int stock = query.value(0).toInt();
                    int newStock = stock - amount;

                    query.prepare("UPDATE products SET stock=:newStock WHERE id=:pid");
                    query.bindValue(":newStock", newStock);
                    query.bindValue(":pid", pid);
                    query.exec();
                }
                // Signal: Einkauf abgeschlossen, Einkaufswagen leeren
                emit purchaseDone(cart);
                clearCart();
            }
            else{
                // Füge noch die Ausgabe der (tlw.) nicht lieferbare Waren und deren vorhandene Menge
                QMessageBox msgBox;
                msgBox.setText("Es sind nicht genug Waren vorhanden. Verringern Sie ihre Bestellung um "+QString::number(diff*(-1))+" Einheiten.");
                msgBox.exec();
            }
        }
        else{
            // User hat nicht genug Geld, zeige Differenz an.
            QMessageBox msgBox;
            msgBox.setText("Sie haben nicht genug Guthaben. Ihnen fehlen "+QString::number(hasEnoughMoney*(-1))+" Geldeinheiten.");
            msgBox.exec();
        }
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Loggen Sie sich bitte ein, um zu bezahlen!");
        msgBox.exec();
    }
}

// ----------------------------------------------------------------------------------
// ---------------------------------------USERMGMT-----------------------------------
// ----------------------------------------------------------------------------------


void sqlfunctions::registerUser(string username, string password){
}

// Gibt User Admin-Privillegien
void sqlfunctions::empowerUser(){
}

// Nimmt User Admin-Privillegien
void sqlfunctions::disempowerUser(){
}

void sqlfunctions::login(string username, string password){
    // Prüfen, ob Username-Password-Kombination existiert
    // Eventuell einen Timeout bei mehrfacher falscher Eingabe einfügen!
    if(1){ //MUSS NOCH KORRIGIERT WERDEN
        // Prüfen ob ein Admin eingeloggt ist
        // Setze entsprechend isAdminLoggedIn auf true bzw. false
        // Wenn ja sende Signal adminLoggedIn aus
        // Gib Admin-Rechte.
        if(1){ //MUSS NOCH KORRIGIERT WERDEN
            emit adminLoggedIn();
            void empowerUser();
        }
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Benutzername oder Passwort inkorrekt!");
        msgBox.exec();
    }
}

