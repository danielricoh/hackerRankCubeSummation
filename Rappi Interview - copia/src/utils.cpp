#include "utils.h"

int Utils::LSOne(int index){
    return (index & (-index));
}
