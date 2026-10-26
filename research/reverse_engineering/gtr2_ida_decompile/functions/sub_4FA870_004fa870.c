void __thiscall sub_4FA870(int this, int a2, int a3)
{
  int v3; // esi
  int v4; // eax
  _DWORD *v5; // eax

  if ( (*(_BYTE *)(this + 12) & 1) != 0 )
  {
    v3 = *(_DWORD *)(this + 4);
    if ( v3 != 105 )
    {
      v4 = *(&dword_91E088 + v3);
      if ( v4 )
      {
        if ( *(_DWORD *)(v4 + 14820) != -1 )
        {
          v5 = (_DWORD *)sub_4FB7D0(v4 + 14824);
          if ( v5 )
            sub_4F7EC0(v5, 1, 0);
        }
      }
    }
  }
  else
  {
    off_16C920C(a2, a3);
  }
}
