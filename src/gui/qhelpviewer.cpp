/*
Copyright (C) 2012 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
*/

#include "qhelpviewer.h"
#include <QVBoxLayout>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QDebug>
#include <QDialogButtonBox>
#include <QDesktopServices>

// Custom page class to handle external links
class QHelpViewerPage : public QWebEnginePage
{
  public:
    QHelpViewerPage(QObject* parent = nullptr): QWebEnginePage(parent) {}

  protected:
    bool acceptNavigationRequest(const QUrl& url, NavigationType type, bool isMainFrame) override
    {
        if (type == NavigationTypeLinkClicked)
        {
            // Open external links in default browser
            QDesktopServices::openUrl(url);
            return false;
        }
        return QWebEnginePage::acceptNavigationRequest(url, type, isMainFrame);
    }
};

QHelpViewer::QHelpViewer(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Handbook"));
    QVBoxLayout* lay = new QVBoxLayout;
    mView = new QWebEngineView;

    // Use custom page to handle external links
    mView->setPage(new QHelpViewerPage(mView));

    lay->addWidget(mView);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Close);
    lay->addWidget(buttonBox);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    setLayout(lay);
}

QHelpViewer::~QHelpViewer()
{
}

void QHelpViewer::setHtml(const QString& filename, const QString& anchor)
{
    mView->load(QUrl(filename));
}
