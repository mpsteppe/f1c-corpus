int __thiscall sub_5B3D50(int *this, int a2)
{
  int v3; // eax
  int v4; // ecx
  _DWORD *v5; // eax
  int v6; // eax
  int result; // eax
  int v8; // [esp+Ch] [ebp-28h] BYREF
  int v9; // [esp+10h] [ebp-24h] BYREF
  int v10; // [esp+14h] [ebp-20h] BYREF
  int v11; // [esp+18h] [ebp-1Ch] BYREF
  _DWORD v12[6]; // [esp+1Ch] [ebp-18h] BYREF

  sub_5B4CC0(*(_DWORD *)(*(_DWORD *)(a2 + 16) + 604), 1);
  sub_593E60(*(_DWORD **)(a2 + 16), &v8, &v9, &v10, &v11);
  v3 = this[1112];
  v10 += v8;
  v4 = *(_DWORD *)(a2 + 16);
  v11 += v9;
  *this = (*(int (__stdcall **)(int, int, int *, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v3 + 144))(
            v3,
            1,
            &v8,
            1,
            *(_DWORD *)(v4 + 124),
            0,
            0);
  v5 = *(_DWORD **)(a2 + 16);
  v12[0] = v5[26] + 1;
  v12[1] = v5[25] + 1;
  v12[2] = v5[21] - 2;
  v12[3] = v5[22] - 2;
  v6 = this[1112];
  v12[4] = 0;
  v12[5] = 1065353216;
  result = (*(int (__stdcall **)(int, _DWORD *))(*(_DWORD *)v6 + 160))(v6, v12);
  *this = result;
  return result;
}
