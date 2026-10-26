int __thiscall sub_6C9387(int this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // eax
  char *v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // eax
  size_t v10; // [esp-Ch] [ebp-28h]
  int v11[4]; // [esp+8h] [ebp-14h] BYREF
  size_t Size; // [esp+18h] [ebp-4h] BYREF

  Size = 0;
  sub_6801F7(v11, 1397051984);
  v2 = sub_68F2C6((_DWORD *)this);
  if ( v2 >= 0 )
  {
    v3 = (*(int (__thiscall **)(_DWORD, size_t *))(**(_DWORD **)(this + 224) + 8))(*(_DWORD *)(this + 224), &Size);
    v2 = v3;
    if ( v3 >= 0 )
    {
      if ( v3
        || (v10 = Size,
            v4 = (*(int (**)(void))(*(_DWORD *)Size + 16))(),
            v5 = (char *)(*(int (__stdcall **)(size_t, int))(*(_DWORD *)Size + 12))(Size, v4),
            v2 = sub_68024C(v11, v5, v10, 1, 0),
            v2 >= 0) )
      {
        v6 = sub_680385(v11);
        v7 = v6;
        if ( v6 > 0x8000 )
        {
          sub_686791(this, 0, 4548, "constant table info exceeds maximum comment size");
          v2 = -2147467259;
        }
        else
        {
          v2 = sub_6C5921(this, v6);
          if ( v2 >= 0 )
          {
            memcpy(
              (void *)(*(_DWORD *)(this + 268) + 4 * v7 + 4),
              (const void *)(*(_DWORD *)(this + 268) + 4),
              4 * *(_DWORD *)(this + 272) - 4);
            v2 = sub_680391(v11, (int *)(*(_DWORD *)(this + 268) + 4), v7);
            if ( v2 >= 0 )
            {
              *(_DWORD *)(this + 272) += v7;
              v8 = *(_DWORD *)(this + 272);
              *(_DWORD *)(this + 288) += v7;
              *(_DWORD *)(this + 284) = v8;
              v2 = 0;
            }
          }
        }
      }
    }
  }
  if ( Size )
  {
    (*(void (__stdcall **)(size_t))(*(_DWORD *)Size + 8))(Size);
    Size = 0;
  }
  sub_680214(v11);
  return v2;
}
