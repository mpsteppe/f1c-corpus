int __thiscall sub_4A0BA0(void *this, int *a2)
{
  char *v3; // eax

  PerDriverRaceCommentary(a2);
  if ( !a2[3250] && !dword_7CE814 )
  {
    GameActionStateMachine(&dword_5EA510, 5, 1);
    SessionStateTransition(1, 0);
    if ( a2[4120] != 1 )
    {
      v3 = (char *)&unk_5EC6D8 + 18624 * sub_4D1B50(0);
      if ( *((_DWORD *)v3 + 4121) == 1 && *((float *)v3 + 4142) + flt_8ACF90 - dbl_8AFEA0 > 60.0 && dword_8AD298 != 19 )
        SessionMenuModeSwitch(this);
    }
  }
  if ( a2[4120] == 1 )
    sub_4D8760(19, 0);
  return 0;
}
