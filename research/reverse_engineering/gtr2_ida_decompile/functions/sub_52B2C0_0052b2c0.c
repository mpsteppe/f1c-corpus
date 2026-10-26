char __thiscall sub_52B2C0(char *this, char a2)
{
  char result; // al
  _DWORD *v3; // ecx
  int v4; // [esp+0h] [ebp-35Ch]
  int v5; // [esp+0h] [ebp-35Ch]
  _DWORD v6[212]; // [esp+Ch] [ebp-350h] BYREF

  result = *this;
  if ( a2 != *this )
  {
    *this = a2;
    if ( (unsigned __int8)sub_4735A0() )
    {
      *(float *)&v4 = dbl_FB1D18;
      sub_51B2A0(v6, 4, 35 - (a2 != 0), 0, 255, v4, 3);
      return sub_4745E0();
    }
    else
    {
      if ( dword_82F4A0 >= 1023 )
      {
        v3 = (_DWORD *)off_9034A4;
      }
      else
      {
        ++dword_82F4A0;
        v3 = (_DWORD *)off_9034A4;
        off_9034A4 += 848;
      }
      *(float *)&v5 = dbl_FB1D18;
      return sub_51B2A0(v3, 4, 35 - (a2 != 0), 0, 255, v5, 3);
    }
  }
  return result;
}
