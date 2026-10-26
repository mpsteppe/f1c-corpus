int __thiscall sub_5A1F80(int this, char *Str, int a3, int a4)
{
  int v5; // ebp
  int v7; // edi
  __int64 v8; // rax
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // edi
  int v14; // ecx
  int v15; // ecx
  int v16; // eax
  int v17; // edi
  int v18; // eax
  int v19; // eax
  int v20; // [esp+10h] [ebp-10h] BYREF
  int v21; // [esp+14h] [ebp-Ch] BYREF
  int v22; // [esp+18h] [ebp-8h] BYREF
  int v23; // [esp+1Ch] [ebp-4h] BYREF

  v5 = 0;
  sub_5A1D50((char *)this, Str);
  if ( sub_59F4D0(*(void **)(this + 16), (int)Str, (int)&v22, (int)&v21, (int)&v20, (int)&v23, 0, 0) == -1 )
  {
LABEL_2:
    sub_5A2660(this);
    return -1;
  }
  v7 = (__int64)(__FYL2X__((double)v22, 0.6931471805599453094) * 1.442695036924675 + 0.5);
  v8 = (__int64)(__FYL2X__((double)v21, 0.6931471805599453094) * 1.442695036924675 + 0.5);
  v9 = *(_DWORD *)(this + 92);
  if ( !v9 || v9 > v7 || v9 > (int)v8 )
  {
    if ( v7 < (int)v8 )
      LODWORD(v8) = v7;
    *(_DWORD *)(this + 92) = v8;
  }
  if ( !strstr(Str, dword_608FD8) )
  {
    if ( (*(_BYTE *)(this + 4) & 1) == 0 )
    {
      v10 = sub_5A4740(&unk_7E6B48);
      v11 = sub_5A4750(v10);
      v12 = v22;
      v13 = v21;
      if ( !v11 )
        goto LABEL_17;
      while ( v12 > *(_DWORD *)(v11 + 284) || v13 > *(_DWORD *)(v11 + 288) )
      {
        v14 = *(_DWORD *)(this + 92);
        v12 >>= 1;
        v13 >>= 1;
        ++v5;
        v22 = v12;
        v21 = v13;
        if ( v14 > 1 )
          *(_DWORD *)(this + 92) = v14 - 1;
      }
      if ( !v5 )
      {
LABEL_17:
        if ( (*(_BYTE *)(this + 4) & 1) == 0 )
        {
          v15 = dword_7E8D7C;
          if ( dword_7E8D7C )
          {
            v16 = *(_DWORD *)(this + 92);
            do
            {
              v12 >>= 1;
              v13 >>= 1;
              if ( v16 > 1 )
                --v16;
              --v15;
            }
            while ( v15 );
            v21 = v13;
            v22 = v12;
            *(_DWORD *)(this + 92) = v16;
          }
        }
      }
    }
    v17 = a4;
    if ( ((unsigned int)&unk_800000 & a4) != 0 )
    {
      v20 = 8;
      goto LABEL_42;
    }
    if ( dword_7E8D50 && sub_5B4BD0(&unk_7E6B48) )
    {
      if ( (*(_DWORD *)(this + 4) & 0x8001) == 0 && v22 >= 8 && v21 >= 8 )
      {
        v20 = 9;
        goto LABEL_42;
      }
      if ( (a4 & 0x800) != 0 )
      {
        v20 = 5;
        goto LABEL_42;
      }
      if ( (a4 & 0x40000) != 0 )
      {
LABEL_35:
        v18 = sub_5B4590(0x200000);
LABEL_41:
        v20 = v18;
LABEL_42:
        if ( (a4 & 0x800) != 0 )
        {
          v19 = a3;
          if ( !a3 )
            v19 = 16711935;
          sub_5A0280(*(_DWORD **)(this + 16), v19);
        }
        *(_DWORD *)(*(_DWORD *)(this + 16) + 44) = *(_DWORD *)(this + 92);
        if ( !dword_7E8D40 )
          v17 = a4 | 0x1000000;
        if ( sub_59F600(*(_DWORD **)(this + 16), Str, v22, v21, v20, v17) )
          goto LABEL_2;
        goto LABEL_49;
      }
    }
    else
    {
      if ( (a4 & 0x800) != 0 )
      {
        v20 = 5;
        goto LABEL_42;
      }
      if ( (a4 & 0x40000) != 0 )
        goto LABEL_35;
    }
    v18 = sub_5B4140(dword_7E8CDC);
    goto LABEL_41;
  }
LABEL_49:
  *(_DWORD *)(this + 92) = *(_DWORD *)(*(_DWORD *)(this + 16) + 44);
  return 0;
}
