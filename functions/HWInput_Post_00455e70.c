int __fastcall sub_455E70(int *a1, int a2)
{
  int result; // eax

  if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(2, aDDevF119992002_13, 5299) )
    DebugLogWrite(&dword_8AD25C, aEnteredHwinput_3);
  CollisionDataFill((int)(a1 + 1), a2, 1);
  if ( a1[1637] )
    ArrayDestructorViaVirtualDispatch(a1 + 1376);
  CollisionObjectDestructor(a1 + 1121);
  CollisionObjectDestructor(a1 + 866);
  CollisionCullCleanup(a1 + 1);
  result = *a1;
  if ( *a1 )
  {
    result = (*(int (__stdcall **)(int))(*(_DWORD *)result + 8))(*a1);
    *a1 = 0;
  }
  return result;
}
