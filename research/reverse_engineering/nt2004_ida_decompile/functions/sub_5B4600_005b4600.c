int __thiscall sub_5B4600(int this, int a2, int a3, _DWORD *a4, int a5, int a6)
{
  int v8; // eax
  int v9; // eax
  int i; // ebp
  int v11; // eax
  _DWORD *v12; // eax
  int v13; // ecx
  int v14; // ebx
  _DWORD *v15; // eax
  _DWORD *v16; // eax
  int result; // eax
  _DWORD v18[16]; // [esp+10h] [ebp-40h] BYREF

  sub_5A9F40(v18);
  if ( !*(_DWORD *)(this + 8636) )
    sub_5AB360((int *)this, 0);
  sub_5932C0(a2, 14);
  v18[8] = 0;
  sub_5AA830((float *)(this + 4568), (int)v18, 0);
  sub_5AA930((int *)this, 256, 0, 0);
  if ( *(_DWORD *)(this + 5160) != 1 )
  {
    v8 = *(_DWORD *)(this + 4448);
    *(_DWORD *)(this + 5160) = 1;
    *(_DWORD *)this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v8 + 200))(v8, 136, 1);
  }
  if ( *(_DWORD *)(this + 5168) )
  {
    v9 = *(_DWORD *)(this + 4448);
    *(_DWORD *)(this + 5168) = 0;
    *(_DWORD *)this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v9 + 148))(v9, 256, this + 8312);
  }
  sub_5AA8A0((int *)this, *(_DWORD **)(this + 4508));
  for ( i = a6;
        i > 0;
        *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD, int))(**(_DWORD **)(this + 4448) + 280))(
                            *(_DWORD *)(this + 4448),
                            2,
                            0,
                            v14) )
  {
    v11 = 2 * i;
    if ( 2 * i >= 1024 )
      v11 = 1024;
    v12 = (_DWORD *)sub_5A8020((int *)this, *(_DWORD **)(this + 4508), 64, 0, v11);
    v13 = i;
    if ( i >= 512 )
      v13 = 512;
    v14 = 0;
    if ( a5 == 405222981 )
    {
      if ( v13 > 0 )
      {
        i -= v13;
        v14 = v13;
        do
        {
          *v12 = *a4;
          v12[1] = a4[1];
          v12[2] = a4[2];
          v12[3] = a4[6];
          v15 = v12 + 6;
          *v15 = a4[3];
          v15[1] = a4[4];
          v15[2] = a4[5];
          v15[3] = a4[7];
          v12 = v15 + 6;
          a4 += 8;
          --v13;
        }
        while ( v13 );
      }
    }
    else if ( v13 > 0 )
    {
      i -= v13;
      v14 = v13;
      do
      {
        *v12 = *a4;
        v12[1] = a4[1];
        v12[2] = a4[2];
        v12[3] = a5;
        v16 = v12 + 6;
        *v16 = a4[3];
        v16[1] = a4[4];
        v16[2] = a4[5];
        v16[3] = a5;
        v12 = v16 + 6;
        a4 += 8;
        --v13;
      }
      while ( v13 );
    }
    sub_5A80B0((int *)this, *(_DWORD *)(this + 4508));
  }
  result = *(_DWORD *)(this + 8636);
  if ( !result )
    return sub_5AB3A0((int *)this, 0);
  return result;
}
