void sub_5F5650()
{
  char *v0; // esi
  char *v1; // esi

  if ( dword_FB2778 )
  {
    v0 = (char *)dword_FB2778 - 4;
    `eh vector destructor iterator'(dword_FB2778, 0x60u, *((_DWORD *)dword_FB2778 - 1), nullsub_7);
    j__free(v0);
    dword_FB2778 = 0;
    dword_910EF4 = 0;
  }
  if ( dword_FB277C )
  {
    v1 = (char *)dword_FB277C - 4;
    `eh vector destructor iterator'(dword_FB277C, 0x60u, *((_DWORD *)dword_FB277C - 1), nullsub_7);
    j__free(v1);
    dword_FB277C = 0;
    dword_910EF8 = 0;
  }
}
