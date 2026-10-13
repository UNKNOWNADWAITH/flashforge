#include <QApplication>
#include <QFileDialog>
#include <QFileInfo>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
int main(int argc, char *argv[])
{
QApplication app(argc, argv);
QApplication::setApplicationName("FlashForge");
QApplication::setApplicationVersion("0.1.0");
QWidget window;
window.setWindowTitle("FlashForge — Linux USB Creator");
window.resize(560, 300);

auto *layout = new QVBoxLayout(&window);

auto *title = new QLabel("FlashForge — development preview");
auto *notice = new QLabel(
    "Read-only prototype. No device formatting or writing is enabled."
);
notice->setWordWrap(true);

auto *selectImage = new QPushButton("Select image");
auto *details = new QLabel("No image selected.");
details->setTextFormat(Qt::PlainText);
details->setWordWrap(true);
details->setTextInteractionFlags(Qt::TextSelectableByMouse);

auto *status = new QLabel(
    "Next milestone: read-only USB device discovery."
);
status->setWordWrap(true);

layout->addWidget(title);
layout->addWidget(notice);
layout->addWidget(selectImage);
layout->addWidget(details);
layout->addStretch();
layout->addWidget(status);

QObject::connect(
    selectImage,
    &QPushButton::clicked,
    &window,
    [&window, details]() {
        const QString path = QFileDialog::getOpenFileName(
            &window,
            "Select an installation or disk image",
            QString(),
            "Image files (*.iso *.img *.raw);;All files (*)"
        );

        if (path.isEmpty())
            return;

        const QFileInfo info(path);

        if (!info.isFile() || !info.isReadable() || info.size() <= 0) {
            QMessageBox::warning(
                &window,
                "Invalid selection",
                "Select a readable, non-empty regular file."
            );
            return;
        }

        const double gib =
            static_cast<double>(info.size()) /
            (1024.0 * 1024.0 * 1024.0);

        details->setText(
            QString(
                "Image: %1\n"
                "Path: %2\n"
                "Size: %3 GiB (%4 bytes)\n\n"
                "Image format and bootability have not been validated."
            )
            .arg(info.fileName())
            .arg(info.absoluteFilePath())
            .arg(gib, 0, 'f', 2)
            .arg(info.size())
        );
    }
);

window.show();
return app.exec();
}
