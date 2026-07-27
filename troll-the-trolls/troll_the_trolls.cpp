namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
    enum class AccountStatus{
        troll,
        guest,
        user,
        mod
    };

// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
    enum class Action{
        read,
        write,
        remove
    };

// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
    bool display_post(AccountStatus as1, AccountStatus as2){
        if(as1==AccountStatus::troll){
            return as2==AccountStatus::troll;
        }else{
            return true;
        }
    }

// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
    bool permission_check(Action a,AccountStatus as){
        switch(a){
            case Action::read:
                return true;
            case Action::write:
                return !(as==AccountStatus::guest);
            case Action::remove:
                return as==AccountStatus::mod;
            default:return false;
        }
    }

// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
    bool valid_player_combination(AccountStatus a1, AccountStatus a2){
        switch(a1){
            case AccountStatus::guest:
                return false;
            case AccountStatus::troll:
                return a2==AccountStatus::troll;
            case AccountStatus::user:
            case AccountStatus::mod:
                return (a2==AccountStatus::mod ||a2==AccountStatus::user);
            default:return false;
        }
    }

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
    bool has_priority(AccountStatus a1,AccountStatus a2){
        /*
        switch(a1){
            case AccountStatus::troll:
                return false;
            case AccountStatus::guest:
                return a2==AccountStatus::troll;
            case AccountStatus::user:
                return (a2==AccountStatus::troll || a2==AccountStatus::guest);
            case AccountStatus::mod:
                return a2!=AccountStatus::mod;
            default:return false;
        }
            */
           return a1>a2;
    }

}  // namespace hellmath
