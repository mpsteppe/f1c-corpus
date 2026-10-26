int __thiscall sub_5B47F0(int this, int a2, _DWORD *a3, int a4, int a5)
{
  int v7; // eax
  int v8; // eax
  int i; // ebp
  int v10; // eax
  _DWORD *v11; // eax
  int v12; // ecx
  int v13; // ebx
  _DWORD *v14; // eax
  _DWORD *v15; // eax
  int result; // eax
  _DWORD v17[16]; // [esp+10h] [ebp-40h] BYREF

  sub_5A9F40(v17);
  if ( !*(_DWORD *)(this + 8636) )
    sub_5AB360((int *)this, 0);
  *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(this + 4448) + 200))(
                      *(_DWORD *)(this + 4448),
                      7,
                      0);
  v17[8] = 0;
  sub_5AA830((float *)(this + 4568), (int)v17, 0);
  sub_5AA930((int *)this, 256, 0, 0);
  if ( *(_DWORD *)(this + 5160) != 1 )
  {
    v7 = *(_DWORD *)(this + 4448);
    *(_DWORD *)(this + 5160) = 1;
    *(_DWORD *)this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v7 + 200))(v7, 136, 1);
  }
  if ( *(_DWORD *)(this + 5168) )
  {
    v8 = *(_DWORD *)(this + 4448);
    *(_DWORD *)(this + 5168) = 0;
    *(_DWORD *)this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v8 + 148))(v8, 256, this + 8312);
  }
  sub_5AA8A0((int *)this, *(_DWORD **)(this + 4512));
  for ( i = a5;
        i > 0;
        *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD, int))(**(_DWORD **)(this + 4448) + 280))(
                            *(_DWORD *)(this + 4448),
                            2,
                            0,
                            v13) )
  {
    v10 = 2 * i;
    if ( 2 * i >= 64 )
      v10 = 64;
    v11 = (_DWORD *)sub_5A8020((int *)this, *(_DWORD **)(this + 4512), 64, 0, v10);
    v12 = i;
    if ( i >= 32 )
      v12 = 32;
    v13 = 0;
    if ( a4 == 405222981 )
    {
      if ( v12 > 0 )
      {
        i -= v12;
        v13 = v12;
        do
        {
          *v11 = *a3;
          v11[1] = a3[1];
          v11[4] = a3[6];
          v14 = v11 + 7;
          *v14 = a3[3];
          v14[1] = a3[4];
          v14[4] = a3[7];
          v11 = v14 + 7;
          a3 += 8;
          --v12;
        }
        while ( v12 );
      }
    }
    else if ( v12 > 0 )
    {
      i -= v12;
      v13 = v12;
      do
      {
        *v11 = *a3;
        v11[1] = a3[1];
        v11[4] = a4;
        v15 = v11 + 7;
        *v15 = a3[3];
        v15[1] = a3[4];
        v15[4] = a4;
        v11 = v15 + 7;
        a3 += 8;
        --v12;
      }
      while ( v12 );
    }
    sub_5A80B0((int *)this, *(_DWORD *)(this + 4512));
  }
  *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(this + 4448) + 200))(
                      *(_DWORD *)(this + 4448),
                      7,
                      *(_DWORD *)(this + 5144));
  result = *(_DWORD *)(this + 8636);
  if ( !result )
    return sub_5AB3A0((int *)this, 0);
  return result;
}
