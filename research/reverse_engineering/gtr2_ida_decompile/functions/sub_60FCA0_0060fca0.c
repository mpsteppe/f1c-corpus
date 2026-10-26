int __thiscall sub_60FCA0(int this, Concurrency::details::ScheduleGroupSegmentBase *a2)
{
  int v3; // eax
  int v4; // ecx
  struct Concurrency::details::ScheduleGroupBase *Group; // eax
  int v6; // ecx
  int v8; // eax

  if ( ((unsigned __int8)Concurrency::details::ScheduleGroupSegmentBase::GetGroup(a2) & 0x70) == 0 )
  {
    v8 = *(_DWORD *)(this + 9548);
    *(_DWORD *)(this + 9012) = 0;
    *(_DWORD *)(this + 8) = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v8 + 228))(v8, 28, 0);
    return 0;
  }
  *(_DWORD *)(this + 9012) = 1;
  if ( *(_DWORD *)(this + 9016) != sub_5DCE60((float *)a2) )
  {
    v3 = sub_5DCE60((float *)a2);
    v4 = *(_DWORD *)(this + 9548);
    *(_DWORD *)(this + 9016) = v3;
    *(_DWORD *)(this + 8) = (*(int (__stdcall **)(int, int, unsigned int))(*(_DWORD *)v4 + 228))(
                              v4,
                              34,
                              (unsigned int)byte_FFFFFF & v3);
  }
  if ( *(float *)(this + 9024) != sub_5DCEB0((float *)a2) )
  {
    *(float *)(this + 9024) = sub_5DCEB0((float *)a2);
    *(_DWORD *)(this + 8) = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(this + 9548) + 228))(
                              *(_DWORD *)(this + 9548),
                              36,
                              *(_DWORD *)(this + 9024));
  }
  if ( *(float *)(this + 9028) != sub_5DCEC0((float *)a2) )
  {
    *(float *)(this + 9028) = sub_5DCEC0((float *)a2);
    *(_DWORD *)(this + 8) = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(this + 9548) + 228))(
                              *(_DWORD *)(this + 9548),
                              37,
                              *(_DWORD *)(this + 9028));
  }
  if ( *(float *)(this + 9020) != sub_5DCED0((float *)a2) )
  {
    *(float *)(this + 9020) = sub_5DCED0((float *)a2);
    *(_DWORD *)(this + 8) = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(this + 9548) + 228))(
                              *(_DWORD *)(this + 9548),
                              38,
                              *(_DWORD *)(this + 9020));
  }
  if ( *(struct Concurrency::details::ScheduleGroupBase **)(this + 9032) == Concurrency::details::ScheduleGroupSegmentBase::GetGroup(a2) )
    return 0;
  Group = Concurrency::details::ScheduleGroupSegmentBase::GetGroup(a2);
  *(_DWORD *)(this + 9032) = Group;
  if ( Group == (struct Concurrency::details::ScheduleGroupBase *)32 )
    v6 = 1;
  else
    v6 = (Group != (struct Concurrency::details::ScheduleGroupBase *)64) + 2;
  *(_DWORD *)(this + 8) = (*(int (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(this + 9548) + 228))(
                            *(_DWORD *)(this + 9548),
                            140,
                            v6);
  return 0;
}
