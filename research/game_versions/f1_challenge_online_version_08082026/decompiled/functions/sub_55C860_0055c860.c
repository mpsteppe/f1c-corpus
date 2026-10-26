int __thiscall sub_55C860(int this, int a2, _DWORD *a3, _DWORD *a4, int a5)
{
  _DWORD *v6; // eax
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int result; // eax
  int v11; // [esp+4h] [ebp-4Ch]
  int v12[16]; // [esp+10h] [ebp-40h] BYREF

  sub_553DB0(v12);
  v6 = (_DWORD *)sub_540F00((int *)this, *(_DWORD **)(this + 4416), 64, 0, 2);
  *v6 = *a3;
  v6[1] = a3[1];
  v6[4] = a5;
  v6[7] = *a4;
  v7 = a4[1];
  v6[11] = a5;
  v6[8] = v7;
  sub_540F90((int *)this, *(_DWORD *)(this + 4416));
  if ( !*(_DWORD *)(this + 5456) )
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(this + 4352) + 136))(*(_DWORD *)(this + 4352));
  *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(this + 4352) + 200))(
                      *(_DWORD *)(this + 4352),
                      7,
                      0);
  v12[8] = 0;
  sub_5546A0((_DWORD *)(this + 4472), v12, 0);
  sub_554790((int *)this, 256, 0, 0);
  if ( *(_DWORD *)(this + 5060) != 1 )
  {
    v8 = *(_DWORD *)(this + 4352);
    *(_DWORD *)(this + 5060) = 1;
    *(_DWORD *)this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v8 + 200))(v8, 136, 1);
  }
  sub_554700((int *)this, *(_DWORD **)(this + 4416));
  v9 = (*(int (__stdcall **)(_DWORD, int, _DWORD, int))(**(_DWORD **)(this + 4352) + 280))(
         *(_DWORD *)(this + 4352),
         2,
         0,
         1);
  v11 = *(_DWORD *)(this + 5048);
  *(_DWORD *)this = v9;
  *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(this + 4352) + 200))(
                      *(_DWORD *)(this + 4352),
                      7,
                      v11);
  result = *(_DWORD *)(this + 5456);
  if ( !result )
  {
    result = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(this + 4352) + 140))(*(_DWORD *)(this + 4352));
    *(_DWORD *)this = result;
  }
  return result;
}
