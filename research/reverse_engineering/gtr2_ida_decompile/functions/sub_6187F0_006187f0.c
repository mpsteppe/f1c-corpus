_BYTE *__thiscall sub_6187F0(_BYTE *this)
{
  DWORD v2; // edx
  int v3; // ebx
  int v4; // ecx
  signed int i; // eax
  unsigned __int8 v6; // al
  DWORD ThreadId; // [esp+10h] [ebp-418h] BYREF
  _BYTE *v9; // [esp+14h] [ebp-414h]
  _DWORD v10[260]; // [esp+18h] [ebp-410h] BYREF

  v9 = this;
  *(_DWORD *)this = &off_72EBB0;
  this[8] = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 4) = 0;
  v10[259] = 0;
  if ( !dword_FB4150 )
  {
    ThreadId = 0;
    dword_FB4154 = CreateEventA(0, 0, 0, 0);
    hEvent = CreateEventA(0, 0, 0, 0);
    dword_FB415C = (int)CreateEventA(0, 0, 0, 0);
    dword_FB4150 = (int)CreateThread(0, 0, sub_618460, 0, 0, &ThreadId);
  }
  if ( Block )
  {
    ++dword_FB414C;
    return this;
  }
  else
  {
    memset(v10, 0, 0x400u);
    Block = operator new(0x400u);
    v2 = 12;
    v3 = 5;
    v4 = 0;
    while ( 1 )
    {
      for ( i = v3 + v4 * v2; v10[i % 256]; ++i )
        ++v3;
      v6 = v3 + v2 * v4;
      *((_BYTE *)Block + v4) = v6;
      v10[v6] = v6 + 1;
      ++v4;
      ThreadId = (int)(v2 + 1) % 35;
      v3 = (v3 + 2) % 9;
      if ( v4 >= 256 )
        break;
      v2 = ThreadId;
    }
    ++dword_FB414C;
    return v9;
  }
}
