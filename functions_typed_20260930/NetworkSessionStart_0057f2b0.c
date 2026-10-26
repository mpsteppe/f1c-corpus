int __thiscall NetworkSessionStart(int *this, int a2)
{
  int *v3; // esi
  int v4; // eax
  int v5; // edx
  _DWORD *v6; // esi
  int v8; // [esp+Ch] [ebp-310h] BYREF
  _BYTE v9[768]; // [esp+10h] [ebp-30Ch] BYREF
  int v10; // [esp+318h] [ebp-4h]

  v3 = this + 592;
  v4 = (*(int (__thiscall **)(int *))(this[592] + 12))(this + 592);
  v9[0] = 0;
  v5 = *v3;
  v10 = 0;
  v8 = 0;
  (*(void (__thiscall **)(int *, _BYTE *, int, int *))(v5 + 16))(v3, v9, v4, &v8);
  v6 = (_DWORD *)(*(int (__thiscall **)(int *))(*this + 88))(this);
  sub_586800(v6, 0, 10, 1, 2, -1);
  SingleFunctionCallWrapper_6a00((int)v9, v8);
  if ( a2 == -1 )
    *(_BYTE *)(v6[18] + 4) = 1;
  else
    (*(void (__thiscall **)(_DWORD, int))(*(_DWORD *)v6[18] + 12))(v6[18], a2);
  return VTableDispatchWithConditionalCall(this, (int)v6);
}

