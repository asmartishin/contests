import random
import string
from datetime import datetime

random.seed(datetime.now())


class Photo:
    def __init__(self, orientation, id, tags):
        self.id = id
        self.orientation = orientation
        self.tags = tags


def read_file(filename):
    photos = []
    for i, l in enumerate(open(filename).readlines()[1:]):
        tokens = l.split()
        photos.append(Photo(tokens[0], i, set(tokens[2:])))
    return photos


def write_file(filename, horizontal, vertical):
    with open(filename, 'w') as f:
        f.write('%d\n' % (len(horizontal) + len(vertical)))
        for i, p in enumerate(horizontal):
            f.write('{o} {id} {tag_count} {tags}\n'.
                    format(o=p.orientation, id=i, tag_count=len(p.tags), tags=' '.join(p.tags)))
        for i, p in enumerate(vertical):
            f.write('{o} {id} {tag_count} {tags}\n'.
                    format(o=p.orientation, id=i + len(horizontal), tag_count=len(p.tags), tags=' '.join(p.tags)))
        for i, p in enumerate(horizontal):
            f.write('{id} {answer}\n'.format(id=i, answer=p.id))
        for i, p in enumerate(vertical):
            f.write('{id} {answer}\n'.format(id=i + len(horizontal), answer=p.id))


def f_max_different(first_tags, second_tags):
    return -len(first_tags & second_tags), len(first_tags | second_tags)


filename = 'd_pet_pictures'
# filename = 'a_example'
# filename = 'e_shiny_selfies'
# filename = 'c_memorable_moments'
photos = read_file('data/{}.txt'.format(filename))
vertical_photos = filter(lambda p: p.orientation == 'V', photos)

processed = set()
pairs = {}
for i, p in enumerate(vertical_photos):
    if len(processed) % (len(vertical_photos)/10) == 0:
        print '{}%: {} from {} processed'.format(100.0*len(processed)/len(vertical_photos), len(processed), len(vertical_photos))
    if p.id not in processed:
        best_pair = -1
        best_res = [-200, -100]
        for another in vertical_photos[i + 1:]:
            if another.id not in processed:
                res = f_max_different(p.tags, another.tags)
                if res[0] > best_res[0] or (res[0] == best_res[0] and res[1] > best_res[1]):
                    best_res = res
                    best_pair = another.id
        pairs[p.id] = best_pair
        processed.add(p.id)
        processed.add(best_pair)

vertical_glued = []
for left, right in pairs.items():
    vertical_glued.append(Photo('V', '{} {}'.format(left, right), photos[left].tags | photos[right].tags))


def randomword(length):
    letters = string.ascii_lowercase
    return ''.join(random.choice(letters) for i in range(length))


write_file('data/{}.txt'.format(filename + randomword(10)), filter(lambda p: p.orientation == 'H', photos), vertical_glued)
