int __thiscall sub_52DDC0(_DWORD **this)
{
  unsigned int v3; // [esp+4h] [ebp-4h] BYREF

  (*(void (__thiscall **)(_DWORD *, unsigned int *, int, _DWORD))(*this[2893] + 8))(this[2893], &v3, 4, 0);
  return (CMpegBase_ProcessHeader((int)this, _byteswap_ulong(v3)) != -1) - 1;
}
