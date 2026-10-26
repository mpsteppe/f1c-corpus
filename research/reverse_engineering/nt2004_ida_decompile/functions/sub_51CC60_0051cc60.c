char __thiscall sub_51CC60(int *this, float a2)
{
  char result; // al
  int v4[52]; // [esp+8h] [ebp-D0h] BYREF

  result = sub_465C10(dword_764D70, *(_DWORD *)(*this + 25248), v4, a2);
  if ( result )
    return sub_4EE5C0(*this, (int)v4, a2);
  return result;
}
