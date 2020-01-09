#include "application.h"

int main()
{
    application app(new window(1280,720,"Title  thingy"), new test_layer());
    app.execute();
    return 0;
}
