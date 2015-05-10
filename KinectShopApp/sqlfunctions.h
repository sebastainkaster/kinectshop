#ifndef SQLFUNCTIONS_H
#define SQLFUNCTIONS_H

#include <iostream>
#include <vector>
#include <algorithm>

#include <QSqlQuery>
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QObject>
#include <string>

#include "product.h"

class product;
using namespace std;

typedef vector<product>::iterator iter;

class sqlfunctions:public QObject{
    Q_OBJECT

    public:
        sqlfunctions();

    signals:
        void        purchaseDone(vector<product> cart);
        void        adminLoggedIn();

    public slots:
        product     isAlreadyInCart(product myProduct);
        void        addToCart(product myProduct);
        void        removeFromCart(product myProduct);
        void        showCart();
        void        clearCart();
        void        disempowerUser();
        void        changeAmount(product myProduct, int newAmount);
        int        checkStock();
        int         checkBalance();
        void        purchase();
        void        registerUser(string username, string password);
        void        login(string username, string password);
        void        empowerUser();

    private:
        vector<product>     cart;
        bool                isLogin;
        bool                isAdminLoggedIn;
        int                 uid;
        QSqlDatabase        db;
};

#endif // SQLFUNCTIONS_H
