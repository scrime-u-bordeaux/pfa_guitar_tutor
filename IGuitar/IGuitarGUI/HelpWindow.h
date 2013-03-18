#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QDialog>

/**
 * @brief Affichage de l'aide
 */
class HelpWindow : public QDialog
{
    Q_OBJECT

    QWebView *page;
    QPushButton *close;
    QVBoxLayout *layout;
public:
    explicit HelpWindow(QWidget *parent = 0);
    ~HelpWindow();
};

#endif // HELPWINDOW_H