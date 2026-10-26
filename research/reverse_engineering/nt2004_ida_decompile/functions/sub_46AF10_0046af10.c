char __thiscall sub_46AF10(CHAR ****this)
{
  char v2; // bl
  double v3; // st7
  double v4; // st7
  float v6; // [esp+8h] [ebp-54h]
  float v7; // [esp+Ch] [ebp-50h]
  _BYTE v8[76]; // [esp+10h] [ebp-4Ch] BYREF

  v2 = 0;
  if ( sub_46AED0((CHAR **)this) )
  {
    v2 = 1;
    sub_57B5D0(v8);
    sub_57B610(1);
    sub_57B690(v8);
    v7 = 1.0 / (double)dword_769AB4;
    sub_451B50();
    v6 = 0.0;
    while ( 1 )
    {
      while ( 1 )
      {
        v3 = sub_57B7C0(v8) + v6;
        if ( v3 >= v7 )
          break;
        Sleep(0);
      }
      v4 = v3 - v7;
      v6 = v4 <= 0.5 ? v4 : 0.5;
      sub_57B690(v8);
      sub_468960(this);
      if ( !sub_46A250(this) )
        break;
      if ( !NumOfElements )
        Sleep(5u);
    }
    sub_469050((int)this);
    sub_46B000(this);
    nullsub_6(v8);
  }
  return v2;
}
