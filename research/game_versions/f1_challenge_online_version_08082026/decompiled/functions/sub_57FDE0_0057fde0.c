int __thiscall sub_57FDE0(void *this)
{
  int v3; // ebp
  void *v4; // eax
  DWORD v5; // eax
  _DWORD *v6; // edi
  _DWORD *v7; // ebp

  if ( !*((_BYTE *)this + 2676) )
    return 8;
  v3 = 0;
  (*(void (__thiscall **)(void *))(*(_DWORD *)this + 116))(this);
  sub_585550(this);
  sub_57C8E0((SOCKET *)this + 591, 0);
  sub_57C8E0((SOCKET *)this + 590, 1);
  sub_585040(this);
  sub_585130(this);
  v4 = (void *)*((_DWORD *)this + 694);
  if ( v4 )
  {
    v5 = WaitForSingleObject(v4, *((_DWORD *)this + 695));
    if ( !v5 || v5 == 128 )
    {
      v6 = (_DWORD *)*((_DWORD *)this + 690);
      if ( v6 )
      {
        do
        {
          v7 = v6;
          v6 = (_DWORD *)v6[1];
          if ( *((_BYTE *)v7 + 8) && *v7 )
            (**(void (__thiscall ***)(_DWORD, int))*v7)(*v7, 1);
          sub_587BCF(v7);
        }
        while ( v6 );
        v3 = 0;
      }
      *((_DWORD *)this + 690) = 0;
      *((_DWORD *)this + 691) = 0;
      *((_DWORD *)this + 692) = 0;
      *((_DWORD *)this + 693) = 0;
      if ( *((_DWORD *)this + 694) )
        ReleaseMutex(*((HANDLE *)this + 694));
    }
  }
  if ( !sub_57FBE0((int)this) )
    return 9;
  return v3;
}
