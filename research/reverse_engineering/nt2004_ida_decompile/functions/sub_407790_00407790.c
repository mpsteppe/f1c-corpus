BOOL __thiscall sub_407790(_DWORD *this, char *FileName, int Offset)
{
  int v4; // eax
  char Buffer[32]; // [esp+8h] [ebp-20h] BYREF

  if ( this[23] != -1 )
    sub_407820(this);
  v4 = _open(FileName, 0x8000, 256);
  this[23] = v4;
  if ( v4 != -1 )
  {
    _lseek(v4, Offset, 0);
    sprintf(Buffer, "%s%d,%d.mp3", asc_5FB910, this[23], this[7]);
    sub_578600(FileName);
    sub_578600(Buffer);
  }
  return this[23] != -1;
}
