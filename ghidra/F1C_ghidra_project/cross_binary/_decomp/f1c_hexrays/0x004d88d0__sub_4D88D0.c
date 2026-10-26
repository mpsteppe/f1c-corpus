// f1c  0x004d88d0  size=128
int __thiscall sub_4D88D0(_DWORD *this)
{
  int v2; // esi
  _DWORD *v3; // edi
  int v4; // esi
  _DWORD *v5; // edi
  int v7; // [esp+Ch] [ebp-4h]

  v7 = dword_7D0410;
  v2 = 0;
  v3 = this + 4;
  do
  {
    if ( (unsigned __int8)sub_4D9290(v2, v7) )
      *v3 = sub_4DAEA0(v2);
    ++v2;
    ++v3;
  }
  while ( v2 < 25 );
  v4 = 0;
  v5 = this + 29;
  do
    *v5++ = sub_4DB420(v4++);
  while ( v4 < 3 );
  if ( (unsigned __int8)sub_4D93E0(0, v7) )
    this[3] = sub_4DC220(0);
  this[54] = sub_4DC290();
  return 0;
}
