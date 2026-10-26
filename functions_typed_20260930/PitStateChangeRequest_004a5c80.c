int __thiscall PitStateChangeRequest(F1CPitMachine *this, int a2)
{
  int result; // eax
  _BYTE *v4; // esi
  int v5; // [esp+0h] [ebp-14h]

  result = this->status;
  if ( a2 != result )
  {
    if ( a2 == 1 || result != 1 && a2 == 2 )
      this->state_enter_time = dbl_8AFEA0;
    v4 = dword_8AAE64;
    if ( dword_83EE60 < 1023 )
    {
      ++dword_83EE60;
      dword_8AAE64 = (char *)dword_8AAE64 + 432;
    }
    *(float *)&v5 = dbl_8AFEA0;
    ProgressBarEventEncode(v4, 6, 1, 1, this->pit_team_index, v5, 0);
    v4[8] = a2;
    return PitStateEventApply(this, v4);
  }
  return result;
}

