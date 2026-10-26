char __thiscall sub_4B07E0(char *this)
{
  char v2; // bl
  CHAR *v3; // eax
  bool v4; // zf
  char *v5; // eax
  _DWORD *v6; // edi
  int v7; // eax
  int v8; // eax
  int v10; // [esp+8h] [ebp-Ch] BYREF
  int v11; // [esp+Ch] [ebp-8h] BYREF
  int v12; // [esp+10h] [ebp-4h] BYREF

  v2 = 0;
  sub_4B0930(1);
  v3 = *(CHAR **)this;
  v4 = *(_DWORD *)this == 0;
  v10 = 0;
  if ( v4 )
    v3 = &byte_629120;
  if ( !sub_5922A0(&v10, v3, *((_DWORD *)this + 8), 1) && v10 )
  {
    v11 = *(_DWORD *)(v10 + 28);
    v12 = *(_DWORD *)(v10 + 32);
    sub_4B0900(&v11);
    sub_4B0900(&v12);
    v5 = *(char **)this;
    if ( !*(_DWORD *)this )
      v5 = &byte_629120;
    v6 = this + 8;
    if ( sub_5A29F0((int)(this + 8), v5, v11, v12, *((_DWORD *)this + 8), 0, 4, 1) || (v7 = *(_DWORD *)(*v6 + 16)) == 0 )
    {
      sub_5A2B00(*v6);
      v8 = v10;
      *v6 = 0;
    }
    else
    {
      sub_59FDC0(0, 0, v7, 0, 0, *(_DWORD *)(v10 + 28), *(_DWORD *)(v10 + 32), 1, 0);
      v8 = v10;
      v2 = 1;
      *((float *)this + 3) = (double)*(int *)(v10 + 28) / (double)v11;
      *((float *)this + 4) = (double)*(int *)(v8 + 32) / (double)v12;
      *((_DWORD *)this + 5) = *(_DWORD *)(v8 + 28);
      *((_DWORD *)this + 6) = *(_DWORD *)(v8 + 32);
    }
    sub_592310(v8);
  }
  return v2;
}
