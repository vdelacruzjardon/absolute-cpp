#ifndef WORLD_H
#define WORLD_H

namespace ncoop {
using std::ostream;

struct World {
    public:
    World( );
    World( bool initial );

    void advance_generation( );
    friend ostream &operator <<( ostream &outputStream, const World &this_world );

    private:
    size_t width, height;
    bool *cell;
};

} // namespace

#endif // WORLD_H
