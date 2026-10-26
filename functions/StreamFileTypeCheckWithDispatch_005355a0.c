int __thiscall sub_5355A0(int this)
{
  if ( !this )
    return -2;
  if ( *(_BYTE *)(this + 92) == 119 && !FileReadLoop(this, 4) )
  {
    ArithmeticComparison_55f0(*(_DWORD *)(this + 64), *(_DWORD *)(this + 76));
    ArithmeticComparison_55f0(*(_DWORD *)(this + 64), *(_DWORD *)(this + 8));
  }
  return FileHandleDestructorWithModeCheck((LPVOID *)this);
}
