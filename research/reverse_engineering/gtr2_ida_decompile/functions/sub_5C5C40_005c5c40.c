_WORD *__thiscall sub_5C5C40(int this)
{
  _WORD *result; // eax

  result = operator new(0x50u);
  if ( result )
  {
    result[38] = 0;
    *(_DWORD *)result = &off_72A210;
    *((_DWORD *)result + 4) = 0;
    *((_DWORD *)result + 5) = 0;
    *((_DWORD *)result + 6) = 0;
    *((_DWORD *)result + 10) = 0;
    *((_DWORD *)result + 11) = 0;
    *((_DWORD *)result + 12) = 0;
    *((_DWORD *)result + 16) = 1065353216;
    *((_DWORD *)result + 17) = 1065353216;
    *((_DWORD *)result + 18) = 1065353216;
  }
  else
  {
    result = 0;
  }
  *((_DWORD *)result + 1) = *(_DWORD *)(this + 4);
  *((_DWORD *)result + 2) = *(_DWORD *)(this + 8);
  *((_DWORD *)result + 3) = *(_DWORD *)(this + 12);
  *((_DWORD *)result + 4) = *(_DWORD *)(this + 16);
  *((_DWORD *)result + 5) = *(_DWORD *)(this + 20);
  *((_DWORD *)result + 6) = *(_DWORD *)(this + 24);
  *((_DWORD *)result + 7) = *(_DWORD *)(this + 28);
  *((_DWORD *)result + 8) = *(_DWORD *)(this + 32);
  *((_DWORD *)result + 9) = *(_DWORD *)(this + 36);
  *((_DWORD *)result + 10) = *(_DWORD *)(this + 40);
  *((_DWORD *)result + 11) = *(_DWORD *)(this + 44);
  *((_DWORD *)result + 12) = *(_DWORD *)(this + 48);
  *((_DWORD *)result + 13) = *(_DWORD *)(this + 52);
  *((_DWORD *)result + 14) = *(_DWORD *)(this + 56);
  *((_DWORD *)result + 15) = *(_DWORD *)(this + 60);
  *((_DWORD *)result + 16) = *(_DWORD *)(this + 64);
  *((_DWORD *)result + 17) = *(_DWORD *)(this + 68);
  *((_DWORD *)result + 18) = *(_DWORD *)(this + 72);
  result[38] = *(_WORD *)(this + 76);
  return result;
}
