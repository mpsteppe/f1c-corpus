_DWORD *__thiscall sub_59D3D0(_DWORD *this, int a2)
{
  _DWORD *v3; // eax
  _DWORD *result; // eax

  sub_59D420();
  v3 = operator new(0x10u);
  if ( v3 )
  {
    result = sub_504470(v3);
    this[81] = result;
    result[3] = a2;
  }
  else
  {
    result = 0;
    this[81] = 0;
    MEMORY[0xC] = a2;
  }
  return result;
}
