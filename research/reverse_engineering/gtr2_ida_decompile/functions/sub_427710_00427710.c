int __thiscall sub_427710(int this)
{
  int v2; // eax
  unsigned int v3; // eax
  int v4; // eax
  _DWORD *v5; // ecx
  int v6; // edx
  int v7; // eax
  _DWORD *v8; // ecx
  int v9; // eax
  _DWORD *v10; // ecx
  int result; // eax
  _DWORD *v12; // ecx

  if ( dword_B64134 == 3 && !(unsigned __int8)sub_4275E0() )
  {
    if ( !*(_BYTE *)(this + 20416) )
    {
      *(_DWORD *)(this + 20444) = 0;
      *(_BYTE *)(this + 21516) = 1;
    }
    v2 = *(_DWORD *)(this + 4);
    *(_DWORD *)(this + 20840) = 0;
    v3 = dword_91BCB0 + v2;
    if ( v3 <= 1 )
      *(_DWORD *)(this + 20848) = v3;
  }
  if ( *(_DWORD *)dword_B640C8 != 6 )
  {
    v4 = 0;
    if ( *(int *)(this + 20620) >= 0 )
    {
      v5 = *(_DWORD **)(this + 20612);
      while ( *v5 )
      {
        ++v4;
        v5 += 2;
        if ( v4 > *(_DWORD *)(this + 20620) )
          goto LABEL_17;
      }
      if ( *(_DWORD *)dword_B72314 == 7 || *(_DWORD *)dword_B72314 == 8 )
      {
        *(_DWORD *)(this + 20852) = 0;
        *(_DWORD *)(this + 20828) = 1203982208;
        *(_DWORD *)(this + 20840) = 1;
      }
      else
      {
        *(_DWORD *)(this + 20840) = 0;
        *(_DWORD *)(this + 20828) = dword_FADE50;
        *(_DWORD *)(this + 20768) = 5;
        *(_DWORD *)(this + 20852) = 1;
        sub_4FB0C0(this, 1, 0);
      }
    }
  }
LABEL_17:
  v6 = *(_DWORD *)(this + 20620);
  v7 = 0;
  if ( v6 >= 0 )
  {
    v8 = *(_DWORD **)(this + 20612);
    while ( *v8 != 5 )
    {
      ++v7;
      v8 += 2;
      if ( v7 > *(_DWORD *)(this + 20620) )
        goto LABEL_23;
    }
    *(_DWORD *)(this + 20828) = 1203982208;
    *(_DWORD *)(this + 20840) = 1;
    *(float *)(this + 20808) = dbl_FB1D18;
    *(_BYTE *)(this + 20820) = 0;
  }
LABEL_23:
  v9 = 0;
  if ( v6 >= 0 )
  {
    v10 = *(_DWORD **)(this + 20612);
    while ( *v10 != 4 )
    {
      ++v9;
      v10 += 2;
      if ( v9 > *(_DWORD *)(this + 20620) )
        goto LABEL_29;
    }
    *(_DWORD *)(this + 20472) = 1;
    *(_DWORD *)(this + 20828) = dword_FADE50;
  }
LABEL_29:
  result = 0;
  if ( v6 >= 0 )
  {
    v12 = *(_DWORD **)(this + 20612);
    while ( *v12 != 14 )
    {
      ++result;
      v12 += 2;
      if ( result > *(_DWORD *)(this + 20620) )
        goto LABEL_35;
    }
    *(_DWORD *)(this + 20840) = 0;
    *(_DWORD *)(this + 20472) = 1;
  }
LABEL_35:
  if ( dword_B64134 == 4 )
  {
    *(_DWORD *)(this + 20852) = 0;
    *(_DWORD *)(this + 20828) = 1203982208;
    *(_DWORD *)(this + 20840) = 1;
  }
  return result;
}
