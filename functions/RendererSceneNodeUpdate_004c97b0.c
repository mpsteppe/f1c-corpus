int __thiscall sub_4C97B0(int this)
{
  _DWORD v3[3]; // [esp+10h] [ebp-Ch] BYREF

  if ( !(unsigned __int8)VirtualStateCheckViaIndex() )
  {
    *(_DWORD *)(this + 28) = 0;
    if ( *(_DWORD *)(this + 32) )
    {
      if ( dword_7C56A8 != 2 )
      {
        memset(v3, 0, sizeof(v3));
        (*(void (__stdcall **)(_DWORD, int, _DWORD *, _DWORD, int, int))(**(_DWORD **)(this + 32) + 4))(
          0,
          this + 8,
          v3,
          LODWORD(flt_7CF2CC),
          1065353216,
          1);
      }
    }
  }
  return 0;
}
