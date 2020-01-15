#include "application.h"

int main()
{
    window* Window = new window(1280,720,"Title");
    test_layer* Test_layer = new test_layer();

    application app(Window, Test_layer);
    app.execute();
    return 0;
}
