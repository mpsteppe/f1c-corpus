int __thiscall sub_59B5F0(_DWORD *this)
{
  int v2; // [esp+8h] [ebp-8h] BYREF
  _BYTE v3[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( (*(unsigned __int8 (__thiscall **)(_DWORD, int *, _BYTE *))(*(_DWORD *)*this + 120))(*this, &v2, v3) )
    return v2;
  else
    return 0;
}
