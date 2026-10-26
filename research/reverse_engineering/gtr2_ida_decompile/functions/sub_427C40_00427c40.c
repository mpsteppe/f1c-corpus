void __thiscall sub_427C40(int this, int a2, int a3)
{
  bool v4; // al
  int v5; // edi
  int v6; // edx
  int v7; // eax
  _DWORD *v8; // ecx
  int v9; // ecx

  switch ( a2 )
  {
    case 4:
      sub_4FB0C0(this, 1, 1);
      break;
    case 5:
      *(_BYTE *)(this + 20844) = 0;
      sub_4FB0C0(this, 0, 0);
      break;
    case 1:
      *(float *)(this + 19648) = dbl_FB1D18 + 2.0;
      break;
    case 15:
      if ( *(_DWORD *)dword_B640C8 == 6 )
        v4 = *(_DWORD *)(*(_DWORD *)this + 19380) == 0;
      else
        v4 = dword_B64134 != 8;
      if ( v4 )
      {
        if ( !*(_BYTE *)(this + 20416) )
          sub_41FC00(this);
      }
      else
      {
        sub_53E6F0(0.0);
        sub_4FF690(0);
      }
      *(_DWORD *)(this + 20840) = 0;
      *(_DWORD *)(this + 20828) = dword_FADE50;
      *(_DWORD *)(this + 20852) = 1;
      *(_BYTE *)(this + 20844) = 1;
      break;
  }
  v5 = *(_DWORD *)(this + 20612);
  if ( v5 )
  {
    v6 = *(_DWORD *)(this + 20620);
    v7 = 0;
    if ( v6 < 0 )
    {
LABEL_21:
      v9 = *(_DWORD *)(this + 20616);
      *(_DWORD *)(this + 20620) = v6 + 1;
      if ( v6 + 1 < v9 )
      {
        *(_DWORD *)(v5 + 8 * (v6 + 1)) = a2;
        *(_DWORD *)(*(_DWORD *)(this + 20612) + 8 * *(_DWORD *)(this + 20620) + 4) = a3;
        sub_427710(this);
        *(_DWORD *)(this + 20620) = -1;
        if ( !a2 && *(_DWORD *)(this + 19380) == 2 )
          *(_BYTE *)(this + 21516) = 0;
      }
      else
      {
        *(_DWORD *)(this + 20620) = v6;
      }
    }
    else
    {
      v8 = *(_DWORD **)(this + 20612);
      while ( *v8 != a2 )
      {
        ++v7;
        v8 += 2;
        if ( v7 > *(_DWORD *)(this + 20620) )
          goto LABEL_21;
      }
    }
  }
}
