#include <qwidget.h>
#include <qboxlayout.h>
#include <widget_helpers.h>


void delete_children(QBoxLayout *layout) {
    QLayoutItem *item_to_delete;
    while ((item_to_delete = layout->takeAt(0)) != nullptr) {
        if (QWidget *widget = item_to_delete->widget()) {
            delete widget;
        }
        delete item_to_delete;
    }
}
