double __thiscall sub_416490(_DWORD *this)
{
  return (double)(int)((this[1] & 0xFFC00000) + ((*this >> 10) & 0x3FF000)) * 0.0000019073486;
}
