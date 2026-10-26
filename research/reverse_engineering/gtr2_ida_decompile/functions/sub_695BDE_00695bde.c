void __thiscall sub_695BDE(_DWORD *this, _DWORD *a2)
{
  _DWORD *v2; // eax
  int v3; // eax
  _DWORD *v4; // [esp-4h] [ebp-8h]

  if ( a2 && a2[1] == 13 )
  {
    v2 = (_DWORD *)a2[4];
    if ( v2 )
    {
      if ( v2[1] == 9 )
      {
        a2[5] = v2[6];
        v3 = v2[7];
      }
      else
      {
        v4 = (_DWORD *)a2[4];
        a2[5] = 1;
        v3 = sub_6951CB(this, v4);
      }
      a2[6] = v3;
    }
    else
    {
      a2[5] = 0;
      a2[6] = 0;
    }
  }
}
