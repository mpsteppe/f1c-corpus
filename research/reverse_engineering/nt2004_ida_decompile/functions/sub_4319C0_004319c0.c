_DWORD *__thiscall sub_4319C0(_DWORD *this, char *FileName)
{
  _DWORD *v3; // edi
  _DWORD *result; // eax
  int v5; // ecx

  v3 = this + 1628;
  sub_4306B0(this + 1628, FileName);
  this[1424] = this[1630];
  result = this + 1440;
  v5 = 8;
  do
  {
    *result = *v3;
    result += 16;
    --v5;
  }
  while ( v5 );
  return result;
}
