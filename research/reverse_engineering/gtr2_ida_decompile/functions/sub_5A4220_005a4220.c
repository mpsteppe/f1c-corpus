char __thiscall sub_5A4220(_DWORD *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // ebp
  int *v5; // ebx
  int v6; // eax
  int v8; // [esp-8h] [ebp-30h]
  int v9; // [esp-4h] [ebp-2Ch]
  int v10; // [esp+0h] [ebp-28h]
  int v11; // [esp+14h] [ebp-14h] BYREF
  int v12; // [esp+18h] [ebp-10h] BYREF
  int i; // [esp+1Ch] [ebp-Ch]
  int v14; // [esp+20h] [ebp-8h]
  int v15; // [esp+24h] [ebp-4h]

  (*(void (__thiscall **)(_DWORD *))(*this + 204))(this);
  v2 = (*(int (__thiscall **)(_DWORD *))(*this + 28))(this);
  v3 = (*(int (__thiscall **)(_DWORD *))(*this + 164))(this);
  v4 = 0;
  v15 = v3;
  for ( i = 0; v4 < v3; i = v4 )
  {
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, int, int))(*this + 176))(this, v4, v2) )
    {
      v12 = 0;
      v11 = 0;
      sub_5A6E60(&v12, &v11);
      v5 = (int *)this[31];
      v10 = v11;
      v9 = v12;
      v14 = *v5;
      v8 = sub_6442E0(v2);
      v6 = sub_5A6E90(v2);
      v4 = i;
      (*(void (__thiscall **)(int *, int, int, int, int, int))(v14 + 52))(v5, i, v6, v8, v9, v10);
      v3 = v15;
    }
    ++v4;
  }
  (*(void (__thiscall **)(_DWORD *, int))(*this + 32))(this, v2);
  (*(void (__thiscall **)(_DWORD *))(*this + 208))(this);
  return 1;
}
