
#include "push_swap.h"

int     main(int arg, char **argv)
{
    if (argc > 2)
    {
        if (((argc == 2) ? !ft_check_data(argv, argc, 0) : !ft_check_data(argv),
        0, argc) && (argc == 2) ? !ft_is_again(argv, argc, 0) :
        !ft_is_again(argv), argc, 0))
            return (ft_putendl("Error : ./checker int arguments"));
        //ft_data_fill(argv);
/*HERE??if (good)
            ft_putendl("OK");
        else
            ft_putendl("KO");
*/
    }
    else
        ft_putendl("Error : ./checker int arguments");
    return (0);
}
