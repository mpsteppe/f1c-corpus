bool __thiscall sub_4773A0(_DWORD *this, int a2)
{
  int v4; // [esp+4h] [ebp-8h] BYREF
  int v5; // [esp+8h] [ebp-4h] BYREF

  DualFieldRead(&v4, &v5);
  return a2
      && v4 > this[72]
      && v4 < this[73]
      && v5 > this[80]
      && v5 < this[81]
      && (unsigned __int8)RectangleBoundsCheck(v4, v5);
}

