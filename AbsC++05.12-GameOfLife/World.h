#ifndef WORLD_H
#define WORLD_H

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

#endif
