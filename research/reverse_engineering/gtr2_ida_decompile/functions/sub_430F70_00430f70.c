int __thiscall sub_430F70(_DWORD *this, int a2)
{
  int v4; // eax
  char v5; // dl
  char v6; // cl
  char v7; // al
  bool v8; // cl
  bool v9; // al
  int m; // esi
  int n; // esi
  int ii; // esi
  int jj; // esi
  int kk; // esi
  int mm; // esi
  int nn; // esi
  char v17; // bl
  int v18; // eax
  int i; // esi
  int k; // esi
  int v21; // eax
  int j; // esi
  int v23; // esi
  int v24; // esi
  unsigned int v25; // kr00_4
  int result; // eax
  int v27; // ebx
  char v28; // [esp+0h] [ebp-14h]
  char v29; // [esp+12h] [ebp-2h]
  char v30; // [esp+13h] [ebp-1h]
  char v31; // [esp+18h] [ebp+4h]

  v27 = dword_16C9B54;
  if ( this[2] != 3 || (v31 = dword_16C9B54, a2 != 4) )
    v31 = 0;
  if ( (unsigned __int8)sub_4735A0(&dword_B6CBA8) )
  {
    v17 = sub_4735E0(&dword_B6CBA8);
    if ( v17 )
    {
      v18 = this[2];
      if ( v18 == 3 || v18 == 4 )
      {
        for ( i = 0; i < dword_757C10; ++i )
          sub_52C3C0(*(&dword_91E088 + i) + 19272);
      }
    }
    if ( a2 == 6 )
    {
      if ( dword_B640C0 != 5
        && (unsigned __int8)sub_5612D0((int)byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\game.cpp", 328) )
      {
        sub_561210((int)byte_FAE910, "Multiplayer mode: setting vehicle places for RACE", v28);
      }
      if ( v17 )
        sub_47A270(&dword_B6CBA8);
      else
        sub_474920(&dword_B6CBA8);
      v21 = dword_757C10;
      for ( j = 0; j < dword_757C10; ++j )
      {
        sub_52C3D0(*(&dword_91E088 + j) + 19272);
        v21 = dword_757C10;
      }
      v23 = 0;
      if ( v21 > 0 )
      {
        do
        {
          sub_52B7E0(*(&dword_91E088 + v23) + 19272);
          v21 = dword_757C10;
          ++v23;
        }
        while ( v23 < dword_757C10 );
      }
      v24 = 0;
      if ( v21 > 0 )
      {
        do
          sub_53E8B0(*(&dword_91E088 + v24++));
        while ( v24 < dword_757C10 );
      }
    }
    else if ( !v31 )
    {
      for ( k = 0; k < dword_757C10; ++k )
        sub_52B7E0(*(&dword_91E088 + k) + 19272);
    }
  }
  else
  {
    if ( a2 == v27 || (v29 = 0, a2 == 2) )
      v29 = v27;
    v4 = this[2];
    if ( (v4 == v27 || v4 == 2) && (a2 == 3 || a2 == 4) )
      v30 = v27;
    else
      v30 = 0;
    if ( v4 == 5 && a2 == 6 )
      v5 = v27;
    else
      v5 = 0;
    if ( (v4 == 3 || v4 == 4) && a2 == 5 )
      v6 = v27;
    else
      v6 = 0;
    if ( v4 == 3 && a2 == 6 )
      v7 = v27;
    else
      v7 = 0;
    if ( v31 )
    {
      v8 = sub_616840("SkipQualifying1") && *(_DWORD *)dword_B72314 == 4;
      v9 = !byte_B6FEEC && *(_DWORD *)dword_B72314 != 4;
      if ( (v8 || v9) && !byte_B722E4 )
      {
        for ( m = 0; m < dword_757C10; ++m )
          sub_52B7E0(*(&dword_91E088 + m) + 19272);
      }
      for ( n = 0; n < dword_757C10; ++n )
        sub_52C3C0(*(&dword_91E088 + n) + 19272);
    }
    else if ( v29 )
    {
      for ( ii = 0; ii < dword_757C10; ++ii )
        sub_52B7E0(*(&dword_91E088 + ii) + 19272);
    }
    else if ( v30 )
    {
      for ( jj = 0; jj < dword_757C10; ++jj )
      {
        sub_52B7E0(*(&dword_91E088 + jj) + 19272);
        sub_52C3D0(*(&dword_91E088 + jj) + 19272);
      }
    }
    else if ( v6 )
    {
      for ( kk = 0; kk < dword_757C10; ++kk )
      {
        sub_52C3C0(*(&dword_91E088 + kk) + 19272);
        sub_52B7E0(*(&dword_91E088 + kk) + 19272);
      }
      if ( *(_DWORD *)dword_B72314 == 4 )
        sub_5363F0(&unk_B76270, 1);
    }
    else if ( v5 )
    {
      for ( mm = 0; mm < dword_757C10; ++mm )
      {
        sub_52C3D0(*(&dword_91E088 + mm) + 19272);
        sub_52B7E0(*(&dword_91E088 + mm) + 19272);
      }
    }
    else if ( v7 )
    {
      for ( nn = 0; nn < dword_757C10; ++nn )
      {
        sub_52C3C0(*(&dword_91E088 + nn) + 19272);
        sub_52B7E0(*(&dword_91E088 + nn) + 19272);
      }
    }
  }
  this[2] = a2;
  v25 = __readeflags();
  result = *(_DWORD *)(dword_16C6E80 - 1822474277);
  __writeeflags(v25);
  dword_B71F24 = a2;
  if ( a2 < result || (result = dword_B71F30, a2 > dword_B71F30) )
    dword_B71F24 = result;
  return result;
}
