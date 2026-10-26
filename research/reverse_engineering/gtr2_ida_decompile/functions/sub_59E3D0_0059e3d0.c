int __thiscall sub_59E3D0(_DWORD *this, int a2, int a3, int *a4)
{
  char v5; // bl
  int v6; // eax
  char v7; // al
  int v8; // edx
  int v10; // [esp-Ch] [ebp-20h]
  int v11; // [esp-8h] [ebp-1Ch]
  int v12; // [esp-4h] [ebp-18h]
  int v13; // [esp+0h] [ebp-14h]
  int v14; // [esp+Ch] [ebp-8h] BYREF

  *a4 = 0;
  (*(void (__thiscall **)(_DWORD *))(*this + 72))(this);
  sub_5A4030(this);
  v13 = *((unsigned __int16 *)this + 1174);
  v12 = this[598];
  v5 = 1;
  v6 = sub_59D7B0();
  *a4 = v6;
  if ( v6 < 0 || (v11 = *((unsigned __int16 *)this + 1174) + 50, v10 = this[597], sub_59D7B0() < 0) )
    v5 = 0;
  sub_630FE0(this + 601);
  v7 = v14;
  *((_BYTE *)this + 2435) = 0;
  *((_BYTE *)this + 2436) = 1;
  *((_BYTE *)this + 2439) = v7;
  *((_BYTE *)this + 2438) = 1;
  if ( !v5 )
    return 6;
  listen(this[597], 0x7FFFFFFF);
  sub_5A42E0(this, 4, v10, v11, v12);
  v8 = *this;
  v14 = 0;
  (*(void (__thiscall **)(_DWORD *, int *, int, int))(v8 + 144))(this, &v14, 2, 1);
  sub_5A4180(this, v13);
  return 0;
}
