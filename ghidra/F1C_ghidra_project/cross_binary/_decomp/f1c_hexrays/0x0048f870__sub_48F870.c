// f1c  0x0048f870  size=373
int __thiscall sub_48F870(_DWORD *this)
{
  int v2; // ebx
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // ebp
  int v8; // eax
  int v9; // ecx
  _DWORD *v10; // ecx
  int v11; // eax
  int v12; // edx
  int v13; // ebx
  int v14; // edi
  int v15; // eax
  int v17; // [esp+10h] [ebp-10h]
  int v18; // [esp+14h] [ebp-Ch]
  int v19; // [esp+18h] [ebp-8h] BYREF
  int v20; // [esp+1Ch] [ebp-4h] BYREF

  v20 = 0;
  v19 = 0;
  sub_498880(&v20, &v19);
  v2 = this[72];
  v3 = this[88] + this[84];
  v4 = (this[73] - v2) / v3;
  if ( v4 >= this[63] )
    v4 = this[63];
  v5 = 0;
  v18 = this[73] - v4 * v3 - v2;
  v17 = 0;
  if ( (int)this[86] > 0 )
  {
    while ( 1 )
    {
      v6 = this[87];
      v7 = 0;
      if ( v6 > 0 )
        break;
LABEL_23:
      v17 = ++v5;
      if ( v5 >= this[86] )
        return (*(int (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
    }
    while ( 1 )
    {
      v8 = v7 + v5 * v6;
      if ( v8 >= 0 && v8 < this[63] )
      {
        v9 = this[60];
        if ( v8 > 0 )
        {
          while ( v9 )
          {
            v9 = *(_DWORD *)(v9 + 4);
            if ( --v8 <= 0 )
              goto LABEL_10;
          }
          goto LABEL_22;
        }
LABEL_10:
        if ( v9 )
        {
          v10 = *(_DWORD **)v9;
          if ( v10 )
            break;
        }
      }
LABEL_22:
      v6 = this[87];
      if ( ++v7 >= v6 )
        goto LABEL_23;
    }
    v11 = this[64];
    v12 = 0;
    v13 = 0;
    if ( v11 )
    {
      if ( v11 == 1 )
        v13 = this[90];
    }
    else
    {
      v12 = this[90];
    }
    v14 = this[72] + v7 * (this[84] + this[88]) - v12;
    if ( this[56] == 1 )
    {
      v15 = v18 / 2;
    }
    else
    {
      if ( this[56] != 2 )
      {
LABEL_21:
        sub_48EA20(v10, v14, this[80] + v17 * (this[85] + this[89]) - v13);
        v5 = v17;
        goto LABEL_22;
      }
      v15 = v18;
    }
    v14 += v15;
    goto LABEL_21;
  }
  return (*(int (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
}
