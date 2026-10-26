// Function: FUN_00462da0 @ 00462da0
// Strings:  [No join failure., Join timed out., Bad password., Game closed., The game is full., Incompatible game versions.]


char * FUN_00462da0(undefined4 param_1)

{
  switch(param_1) {
  case 1:
    return s_Incompatible_game_versions__005c6274;
  case 2:
    return s_The_game_is_full__005c6260;
  case 3:
    return s_Game_closed__005c6250;
  case 4:
    return s_Bad_password__005c6240;
  case 5:
    return s_Join_timed_out__005c6230;
  default:
    return s_No_join_failure__005c621c;
  }
}


