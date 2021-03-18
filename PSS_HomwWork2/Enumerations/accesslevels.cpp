#include "accesslevels.h"

std::string getAccessLevelName(AccessLevel l) {
    switch (l) {
        case AccessLevel::no_level:return"no_level";
        case AccessLevel::blue    :return"blue";
        case AccessLevel::green   :return"green";
        case AccessLevel::yellow  :return"yellow";
        case AccessLevel::red     :return"red";
        case AccessLevel::black   :return"black";
    }
    return "no_level";
}

