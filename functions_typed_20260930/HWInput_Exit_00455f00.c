int __thiscall sub_455F00(HCURSOR *this)
{
  int result; // eax

  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_13, 5321) )
    DebugLogWrite(&dword_8AD25C, aEnteredHwinput_4);
  CollisionObjectDestructor(this + 1121);
  CollisionObjectDestructor(this + 866);
  CursorResourceCleanup(this + 815);
  CollisionCullCleanup(this + 1);
  result = (int)*this;
  if ( *this )
  {
    result = (*(int (__stdcall **)(HCURSOR))(*(_DWORD *)result + 8))(*this);
    *this = 0;
  }
  if ( byte_7D13A0 == 1 )
  {
    result = ModuleUnload();
    this[1732] = (HCURSOR)-1;
  }
  return result;
}

