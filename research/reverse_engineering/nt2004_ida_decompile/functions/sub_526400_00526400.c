int __thiscall sub_526400(int *this)
{
  int *v2; // edi
  int *v3; // ebx
  _DWORD *v4; // ebp
  int result; // eax
  int v6; // edx
  int v7; // ecx

  v2 = this + 3;
  v3 = this + 1;
  v4 = this + 2;
  result = sub_526500(this + 3);
  *this = result;
  if ( !result )
  {
    v6 = *v3 - 0x8000;
    v7 = *v2 - 0x8000;
    *v4 -= 0x8000;
    *v3 = v6;
    *v2 = v7;
  }
  return result;
}
