int __thiscall GameMode(int this)
{
  int result; // eax
  _BYTE v3[128]; // [esp+4h] [ebp-80h] BYREF

  if ( dword_5EB10C )
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 12))(dword_5EB10C);
  BufferInitWith10fDefaults(flt_5EA618);
  switch ( dword_7D0410 )
  {
    case 1:
    case 2:
    case 3:
      GuardedFunctionDispatch((_DWORD *)this, (int)aSelectcircuitp);
      result = -1;
      break;
    case 4:
      SessionSceneInitChain(&unk_7CE24C);
      GuardedFunctionDispatch((_DWORD *)this, (int)aChResume);
      result = -1;
      break;
    case 5:
      if ( SessionStateCheck(dword_7CD25C) == 3 )
      {
        LookupDispatch(*(_DWORD **)(this + 64), (int)aMpclientgrid, -1);
        FAILWRONGDESCRIPTION(v3);
        NetworkEntrantSetupWithIDCheck(dword_7CD25C, (int)v3, 0);
        SessionConfigWriteback((int)v3);
        if ( (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 24) )
        {
          SeasonSceneNameAccessor();
          TrackSceneConfigLoader();
        }
        dword_5CC9E8 = 1;
        EmptyStub_0170();
      }
      result = -1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

