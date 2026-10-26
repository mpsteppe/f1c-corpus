int __stdcall sub_4D1140(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  if ( (int)a1[4649] < 0 )
    sub_4C6F10(a1);
  return IndexedStructDataRead(dword_5EA2C0, a1[4649], a1[4650], a2, a3);
}
